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

#ifndef DATA_CONVERSION_HPP
#define DATA_CONVERSION_HPP

#include "dmpc/optim/optim_util.hpp"
#include "dmpc/info/communication_data.hpp"

class DataConversion
{
public:
	/*Insert integer into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const int a);
	/*Insert unsigned int into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const unsigned int a);
	/*Insert typeRNum into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const typeRNum a);
	/*Insert char into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const char a);
	/*Insert vector of typeRNums into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const std::vector<typeRNum>& a);
	/*Insert bool into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const bool a);
	/*Insert string into char array*/
	static void insert_into_charArray(const std::shared_ptr<std::vector<char>>& data, unsigned int& pos, const std::string& a);

	/*Read int from char array*/
	static void read_from_charArray(const std::vector<char>& data, unsigned int& pos, int& a);
	/*Read unsigned int from char array*/
	static void read_from_charArray(const std::vector<char>& data, unsigned int& pos, unsigned int& a);
	/*Read typeRNum from char array*/
	static void read_from_charArray(const std::vector<char>& data, unsigned int& pos, typeRNum& a);
	/*Read bool from char array*/
	static void read_from_charArray(const std::vector<char>& data, unsigned int& pos, bool& a);
	/*Read vector of typeRNums from char array*/
	static void read_from_charArray(const std::vector<char>& data, unsigned int& pos, std::vector<typeRNum>& a);
	/*Read string from char array*/
	static void read_from_charArray(const std::vector<char>& data, unsigned int& pos, std::string& a);

	/*Skip bool in char array*/
	static void skip_in_charArray_bool(const std::vector<char>& data, unsigned int& pos);
	/*Skip char in char array*/
	static void skip_in_charArray_char(const std::vector<char>& data, unsigned int& pos);
	/*Skip int in char array*/
	static void skip_in_charArray_int(const std::vector<char>& data, unsigned int& pos);
	/*Skip typeRNum in char array*/
	static void skip_in_charArray_typeRNum(const std::vector<char>& data, unsigned int& pos);
	/*Skip vector of typeRNums in char array*/
	static void skip_in_charArray_vecTypeRNum(const std::vector<char>& data, unsigned int& pos);
	/*Skip string in char array*/
	static void skip_in_charArray_string(const std::vector<char>& data, unsigned int& pos);
	
	/*Convert ADMM step to integer*/
	static const int ADMMStep_to_int(dmpc::ADMMStep step);
	/*Convert integer to ADMM step*/
	static const dmpc::ADMMStep Int_to_ADMMStep(int a);

	/*Erase element from list of integers*/
	static void erase_element_from_vector(std::vector<int>& list, const int element);
	/*Erase element from list of coupling infos*/
	static void erase_element_from_vector(std::vector<std::shared_ptr<dmpc::CouplingInfo>>& list, const dmpc::CouplingInfo& element);
	/*Erase element from list of agent infos*/
	static void erase_element_from_vector(std::vector< dmpc::AgentInfo >& list, const dmpc::AgentInfo& element);
	/*Erase element from list of coupling infos*/
	static void erase_element_from_vector(std::vector< dmpc::CouplingInfo >& list, const dmpc::CouplingInfo& element);
	/*Erase element from list of communication data*/
	static void erase_element_from_vector(std::vector< dmpc::CommunicationDataPtr >& list, const dmpc::CommunicationDataPtr& element);
	/*Erase element from list of neighbor pointers*/
	static void erase_element_from_vector(std::vector< dmpc::NeighborPtr >& list, const dmpc::NeighborPtr& element);
	/*Erase element from list of agents*/
	static void erase_element_from_vector(std::vector< dmpc::AgentPtr >& list, const dmpc::AgentInfo& element);

	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector<int>& list, const int element);
	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector<std::shared_ptr<dmpc::CouplingInfo>>& list, const dmpc::CouplingInfo& element);
	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector< dmpc::CouplingInfo >& list, const dmpc::CouplingInfo& element);
	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector< dmpc::CommunicationDataPtr >& list, const std::shared_ptr<dmpc::CommunicationData>& element);
	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector<dmpc::NeighborPtr>& list, const int neighbor_id);
	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector<dmpc::NeighborPtr>& list, const dmpc::NeighborPtr& element);
	/*Returns true if element is in vector*/
	static const bool is_element_in_vector(const std::vector<dmpc::AgentInfo>& list, const int id);

	/*Returns specific element from vector*/
	static const dmpc::NeighborPtr get_element_from_vector(const std::vector<dmpc::NeighborPtr>& list, const int id);
};

#endif// DATA_CONVERSION_HPP
