// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2022-2025, The OpenROAD Authors

#pragma once

#include <string>

#include "odb/db.h"
#include "utl/Logger.h"

namespace sta {
class dbNetwork;
}

namespace upf {

// bool create_power_domain(utl::Logger* logger,
//                          odb::dbBlock* block,
//                          const std::string& name);

bool update_power_domain(utl::Logger* logger,
                         odb::dbBlock* block,
                         const std::string& name,
                         const std::string& element);

bool create_logic_port(utl::Logger* logger,
                       odb::dbBlock* block,
                       const std::string& name,
                       const std::string& direction);

bool create_power_switch(utl::Logger* logger,
                         odb::dbBlock* block,
                         const std::string& name,
                         const std::string& power_domain);

bool update_power_switch_control(utl::Logger* logger,
                                 odb::dbBlock* block,
                                 const std::string& name,
                                 const std::string& control_port,
                                 const std::string& control_net);

bool update_power_switch_acknowledge(utl::Logger* logger,
                                     odb::dbBlock* block,
                                     const std::string& name,
                                     const std::string& port,
                                     const std::string& net,
                                     const std::string& boolean);

bool update_power_switch_on(utl::Logger* logger,
                            odb::dbBlock* block,
                            const std::string& name,
                            const std::string& on_state,
                            const std::string& port,
                            const std::string& boolean);

bool update_power_switch_input(utl::Logger* logger,
                               odb::dbBlock* block,
                               const std::string& name,
                               const std::string& in_port,
                               const std::string& net);

bool update_power_switch_output(utl::Logger* logger,
                                odb::dbBlock* block,
                                const std::string& name,
                                const std::string& out_port,
                                const std::string& net);

bool set_isolation(utl::Logger* logger,
                   odb::dbBlock* block,
                   const std::string& name,
                   const std::string& power_domain,
                   bool update,
                   const std::string& applies_to,
                   const std::string& clamp_value,
                   const std::string& signal,
                   const std::string& sense,
                   const std::string& location);

bool use_interface_cell(utl::Logger* logger,
                        odb::dbBlock* block,
                        const std::string& power_domain,
                        const std::string& strategy,
                        const std::string& cell);

bool set_domain_area(utl::Logger* logger,
                     odb::dbBlock* block,
                     const std::string& domain,
                     const odb::Rect& area);

bool eval_upf(sta::dbNetwork* network,
              utl::Logger* logger,
              odb::dbBlock* block);

bool update_power_switch_cell(utl::Logger* logger,
                              odb::dbBlock* block,
                              const std::string& name,
                              odb::dbMaster* cell);

bool update_power_switch_port_map(utl::Logger* logger,
                                  odb::dbBlock* block,
                                  const std::string& name,
                                  const std::string& model_port,
                                  const std::string& switch_port);

bool create_or_update_level_shifter(
    utl::Logger* logger,
    odb::dbBlock* block,
    const std::string& name,
    const std::string& domain,
    const std::string& source,
    const std::string& sink,
    const std::string& use_functional_equivalence,
    const std::string& applies_to,
    const std::string& applies_to_boundary,
    const std::string& rule,
    const std::string& threshold,
    const std::string& no_shift,
    const std::string& force_shift,
    const std::string& location,
    const std::string& input_supply,
    const std::string& output_supply,
    const std::string& internal_supply,
    const std::string& name_prefix,
    const std::string& name_suffix,
    bool update);

bool add_level_shifter_element(utl::Logger* logger,
                               odb::dbBlock* block,
                               const std::string& level_shifter_name,
                               const std::string& element);

bool exclude_level_shifter_element(utl::Logger* logger,
                                   odb::dbBlock* block,
                                   const std::string& level_shifter_name,
                                   const std::string& exclude_element);

bool handle_level_shifter_instance(utl::Logger* logger,
                                   odb::dbBlock* block,
                                   const std::string& level_shifter_name,
                                   const std::string& instance_name,
                                   const std::string& port_name);

bool set_domain_voltage(utl::Logger* logger,
                        odb::dbBlock* block,
                        const std::string& domain,
                        float voltage);

bool set_level_shifter_cell(utl::Logger* logger,
                            odb::dbBlock* block,
                            const std::string& shifter,
                            const std::string& cell,
                            const std::string& input,
                            const std::string& ouput);

void write_upf(utl::Logger* logger,
               odb::dbBlock* block,
               const std::string& file);
}  // namespace upf
