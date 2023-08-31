// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#include "ExamplePublisher.hpp"

namespace module {

void ExamplePublisher::init() {
    invoke_init(*p_example_pub);
}

void ExamplePublisher::ready() {
    invoke_ready(*p_example_pub);
}

} // namespace module
