// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include <chrono>

#include "example_publisherImpl.hpp"

namespace module {
namespace example_pub {

void example_publisherImpl::init() {
}

void example_publisherImpl::ready() {
    this->publisher_thread = std::thread([this]() {
        while (true) {
            this->mod->p_example_pub->publish_something(42);
            types::units::Voltage voltage;
            voltage.L1.emplace(this->mod->config.voltage);
            this->mod->p_example_pub->publish_voltage_V(voltage);
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
    this->steady_timer.timeout([this]() { EVLOG_info << "timeout"; }, std::chrono::seconds(3));
}

bool example_publisherImpl::handle_do_something(std::string& arg) {
    if (arg == "hello there") {
        return true;
    }
    return false;
}

} // namespace example_pub
} // namespace module
