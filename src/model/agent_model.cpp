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

#include "dmpc/model/agent_model.hpp"

namespace dmpc
{


AgentModel::AgentModel(unsigned int Nxi, unsigned int Nui, unsigned int Ngi, unsigned int Nhi,
                       const std::vector<double>& umin, const std::vector<double>& umax,
                       const std::vector<typeRNum>& model_parameters,
                       const std::vector<typeRNum>& cost_parameters,
                       const std::string& model_name,
                       const LoggingPtr& log)
    : Nxi_(Nxi), Nui_(Nui), Ngi_(Ngi), Nhi_(Nhi),
      umin_(umin), umax_(umax),
      model_parameters_(model_parameters),
      cost_parameters_(cost_parameters),
      model_name_(model_name),
      log_(log)
{
	if (umin.size() != Nui || umax.size() != Nui)
        log_->print_debug(Logging::Error) << "Size of control limits does not equal number of controls" << std::endl;
}

AgentModel::~AgentModel()
{
}

const unsigned int AgentModel::get_Nxi() const
{
    return Nxi_;
}

const unsigned int AgentModel::get_Nui() const
{
    return Nui_;
}

const unsigned int AgentModel::get_Ngi() const
{
    return Ngi_;
}

const unsigned int AgentModel::get_Nhi() const
{
    return Nhi_;
}

const void AgentModel::get_controlLimits(std::vector<typeRNum>& umin, std::vector<typeRNum>& umax)
{
    for( int k = 0; k < umin_.size(); ++k )
    {
        umin[k] = umin_[k];
        umax[k] = umax_[k];
    }
}

const std::vector<typeRNum> AgentModel::get_costParameters() const
{
    return cost_parameters_;
}

const std::vector<typeRNum> AgentModel::get_modelParameters() const
{
    return model_parameters_;
}

const std::string AgentModel::get_modelName() const
{
    return model_name_;
}

}
