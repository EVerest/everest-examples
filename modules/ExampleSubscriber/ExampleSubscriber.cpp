// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#include "ExampleSubscriber.hpp"

namespace module {

void ExampleSubscriber::init() {
    invoke_init(*p_main);
}

void ExampleSubscriber::ready() {
    invoke_ready(*p_main);
}

} // namespace module
