/* This file is part of GRAMPC-D - (https://github.com/DanielBurk/GRAMPC-D.git)
 *
 * GRAMPC-D -- A software framework for distributed model predictive control (DMPC)
 * based on the alternating direction method of multipliers (ADMM).
 *
 * Copyright 2020 by Daniel Burk, Andreas Voelz, Knut Graichen
 * All rights reserved.
 *
 * GRAMPC-D is distributed under the BSD-3-Clause license, see LICENSE.txt
 *
 */

#include "dmpc/model/coupling_model.hpp"

namespace dmpc
{

CouplingModel::CouplingModel(unsigned int Nxi, unsigned int Nui, unsigned int Nxj, unsigned int Nuj, unsigned int Ngij, unsigned int Nhij,
                             const std::vector<typeRNum>& model_parameters,
                             const std::string& model_name)
    : Nxi_(Nxi), Nui_(Nui), Nxj_(Nxj), Nuj_(Nuj), Ngij_(Ngij), Nhij_(Nhij),
      model_parameters_(model_parameters),
      model_name_(model_name)
{}

CouplingModel::~CouplingModel()
{}

const unsigned int CouplingModel::get_Nxi() const
{
    return Nxi_;
}

const unsigned int CouplingModel::get_Nui() const
{
    return Nui_;
}

const unsigned int CouplingModel::get_Nxj() const
{
    return Nxj_;
}

const unsigned int CouplingModel::get_Nuj() const
{
    return Nuj_;
}

const unsigned int CouplingModel::get_Ngij() const
{
    return Ngij_;
}

const unsigned int CouplingModel::get_Nhij() const
{
    return Nhij_;
}

const std::vector<typeRNum> CouplingModel::get_modelParameters() const
{
    return model_parameters_;
}

const std::string CouplingModel::get_modelName() const
{
    return model_name_;
}

}
