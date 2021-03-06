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

#ifndef COUPLING_STATE_HPP
#define COUPLING_STATE_HPP

#include "dmpc/util/types.hpp"

namespace dmpc
{

/**
 * @brief Coupling variable $ z = [z_x, z_u] $.
 */
struct CouplingState
{
public:

    int i_;

    typeRNum t0_;
    std::vector<typeRNum> t_;

    std::vector<typeRNum> z_x_;
    std::vector<typeRNum> z_u_;
    std::vector<typeRNum> z_v_;
};

typedef std::shared_ptr<CouplingState> CouplingStatePtr;

}

#endif // COUPLING_STATE_HPP
