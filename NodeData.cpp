//
// Created by geanc on 27 ene. 2022.
//

#include "NodeData.h"

NodeData::NodeData(int dd) {
    this->dData = dd;
}

NodeData::operator string() {
    return to_string(dData)+",";
}

