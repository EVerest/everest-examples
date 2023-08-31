// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include "emptyImpl.hpp"

namespace module {
namespace main {

void emptyImpl::init() {
}

void emptyImpl::ready() {
    this->mod->r_example_pub->subscribe_something([this](int something) {
        EVLOG_info << "Received something: " << something;
    });

    this->mod->r_example_pub->subscribe_voltage_V([this](types::units::Voltage voltage) {
        EVLOG_info << "Received voltage: " << voltage;
    });

    if (this->mod->r_example_pub->call_do_something("hi")) {
        EVLOG_info << "true";
    } else {
        EVLOG_info << "false";
    }

    if (this->mod->r_example_pub->call_do_something("hello there")) {
        EVLOG_info << "general kenobi";
    } else {
        EVLOG_info << "?";
    }
}

} // namespace main
} // namespace module
