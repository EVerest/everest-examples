// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#include "ExamplePublisher.hpp"

#include <everest/gpio/gpio.hpp>
#include <everest/io/event/fd_event_handler.hpp>

namespace module {

void ExamplePublisher::init() {
    invoke_init(*p_example_pub);

    Everest::Gpio test_gpio;
    everest::lib::io::event::fd_event_handler ev_handler;
}

void ExamplePublisher::ready() {
    invoke_ready(*p_example_pub);
}

} // namespace module
