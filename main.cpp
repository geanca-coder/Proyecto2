#include "TwoFour.h"
#include <chrono>
#include <random>
/*
 SE BUSCO ESTAR LO MAS APEGADO AL CODIGO ORIGINAL
 PROPUESTO POR EL PROFESOR EN LA OPCION 2 DEL SWITCH
 SE MANTUVIERON LAS LINEAS COMENTADAS POR APEGO AL CODIGO ORIGINAL
 Y PORQUE SE CONSIDERAN SUCIAS A LA HORA DE LA IMPRESION A LA HORA DE LA
 EJECUCION DEL PROGRAMA.

 SIN EMBARGO SE CONSIDERO DEJARLAS PARA QUE SE EVIDENCIE DE LA MEJOR MANERA
 EL APEGO DE TRADUCIR EL CODIGO JAVA A C++

 LA EJECUCION DEL PROGRAMA ES LA MISMA Y NO AFECTA CON LOS PUNTOS A EVALUAR del PROYECTO
 */
double get_random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
int nextInt(int n){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, n);
    return dis(gen);
}
bool numbersOnly(string s) {
    try{
        int i =0;
        for(char & e : s) {
            if(i==0 && e=='-') {
                i++;
                continue;
            }
            if (!isdigit(e)) {
                throw runtime_error("RUNTIME EXCEPTION, INVALID INPUT, NUMBERS ONLY!!");
            }
        }
    }catch(runtime_error & e){
        cout<<e.what()<<endl;
        return false;
    }
    return true;
}
int main() {
    auto* theTree = new TwoFour;
    int n;
    int choice;
    bool out = true;
    while(out){
            cout<<"1. Insert n random Integers\n"
                  <<"2. Perform 2n operations with probability\n3. Print In Order"
                  <<"\n4. View Tree level by level\n5. Insert an element\n6. Delete an element"
                  <<"\n7. find an element\n8. Quit"<<endl;
            cin>>choice;

            while (cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"RUNTIME ERROR NUMBERS ONLY"<<endl<<endl;
                cout<<"1. Insert n random Integers\n"
                    <<"2. Perform 2n operations with probability\n3. Print In Order"
                    <<"\n4. View Tree level by level\n5. Insert an element\n6. Delete an element"
                    <<"\n7. find an element\n8. Quit"<<endl;
                cin>>choice;
            }
            switch (choice) {
                case 1: {
                    string nS;
                    cout << "Enter the value of n" << endl;
                    cin >> nS;
                    if (not numbersOnly(nS)) {
                        continue;
                    }
                    n = stoi(nS);
                    for (int i = 1; i < n + 1; i++) {
                        int random = nextInt(10000);
                        Node *present = theTree->find(random);
                        if (present) {
                        } else {
                            theTree->insert(random);
                        }
                    }
                    cout<<"Succesful insertion!!"<<endl;
                }
                    break;
                case 2: {
                    string nS;
                    cout<<"Enter the value of n"<<endl;
                    cin>>nS;
                    if(not numbersOnly(nS)) continue;
                    n = stoi(nS);
                    int operation =0;
                    int searchCount =0;
                    int insertCount =0;
                    int deleteCount =0;
                    auto start = chrono::steady_clock::now();
                    while(operation <(2*n)){
                        double rand = get_random();
                        if(rand < 0.4){
                            int x = nextInt(n);
                            Node* present = theTree->find(x);
                            if(present) {
                                //cout<<"Data already present"<<endl;
                            }
                            else theTree->insert(x);
                            operation++;
                            insertCount++;
                        }
                        rand = get_random();
                        if(rand<0.25){
                            int x = nextInt(n);
                            Node* del = theTree->find(x);
                            if(del){
                                if(theTree->erase(del,x)){
   //                                 cout<<"Deleted "<<x<<endl;
                                }else {
                                    //cout<<"Not deleted!!!"<<endl;
                                }
                            }else {
                                //cout<<"Could not find "<<x<<endl;
                            }
                            operation++;
                            deleteCount++;
                        }
                        rand = get_random();
                        if(rand<0.35){
                            theTree->find(nextInt(n));
                            operation++;
                            searchCount++;
                        }
                    }
                    auto end = chrono::steady_clock::now();
                    cout<<"Total No. of search operations performed :"<<searchCount<<endl;
                    cout<<"Total No. of delete operations performed :"<<deleteCount<<endl;
                    cout<<"Total No. of insert operations performed :"<<insertCount<<endl;
                    cout<<"Total Time Taken:" << chrono::duration_cast<chrono::nanoseconds>(end -start).count()<< " nanoseconds"<<endl;
                }
                    break;
                case 3:{
                    cout<<"In order: "<<endl;
                    cout<<theTree->displayTree(1);
                }
                    break;
                case 4:{
                    cout<<"Tree: "<<endl;
                    cout<<theTree->displayTree(0)<<endl;
                }
                    break;
                case 5:{
                    string nS;
                    cout<<"Enter value to insert: "<<endl;
                    cin>>nS;
                    if(not numbersOnly(nS)) continue;
                    int value = stoi(nS);
                    Node* present = theTree->find(value);
                    if (present){
                        cout<<"Data Already present!!"<<endl;
                    }else{
                        theTree->insert(value);
                    }
                }
                break;
                case 6:{
                    string nS;
                    cout<<"Enter value to delete: "<<endl;
                    cin>>nS;
                    if(not numbersOnly(nS)) continue;
                    int value = stoi(nS);
                    Node* del = theTree->find(value);
                    if(del) {
                        if (theTree->erase(del, value)) {
                            cout << "Deleted " << value << endl;
                        } else {
                            cout << "Not deleted" << endl;
                        }
                    }else cout<<"Could not find "<<value<<endl;

                }
                    break;
                case 7:{
                    string nS;
                    cout<<"Enter value to find: "<<endl;
                    cin>>nS;
                    if(not numbersOnly(nS)) continue;
                    int value = stoi(nS);
                    Node* found = theTree->find(value);
                    if(found) cout<<"Found "<<value<<endl;
                    else cout<<"Could not find "<<value<<endl;
                }
                    break;
                case 8:{
                    cout<<"Thank you!!!"<<endl;
                    out = false;
                }
                    break;
                default:{
                    cout<<"OPTION ENTERED IS OUT OF RANGE"<<endl;
                }
                    break;
            }
    }

    delete theTree;

    return 0;
}
