// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#ifndef EXAMPLE_PUB_EXAMPLE_PUBLISHER_IMPL_HPP
#define EXAMPLE_PUB_EXAMPLE_PUBLISHER_IMPL_HPP

//
// AUTO GENERATED - MARKED REGIONS WILL BE KEPT
// template version 3
//

#include <generated/interfaces/example_publisher/Implementation.hpp>

#include "../ExamplePublisher.hpp"

// ev@75ac1216-19eb-4182-a85c-820f1fc2c091:v1
// insert your custom include headers here
#include <everest/timer.hpp>
// ev@75ac1216-19eb-4182-a85c-820f1fc2c091:v1

namespace module {
namespace example_pub {

struct Conf {};

class example_publisherImpl : public example_publisherImplBase {
public:
    example_publisherImpl() = delete;
    example_publisherImpl(Everest::ModuleAdapter* ev, const Everest::PtrContainer<ExamplePublisher>& mod,
                          Conf& config) :
        example_publisherImplBase(ev, "example_pub"), mod(mod), config(config){};

    // ev@8ea32d28-373f-4c90-ae5e-b4fcc74e2a61:v1
    // insert your public definitions here
    // ev@8ea32d28-373f-4c90-ae5e-b4fcc74e2a61:v1

protected:
    // command handler functions (virtual)
    virtual bool handle_do_something(std::string& arg) override;

    // ev@d2d1847a-7b88-41dd-ad07-92785f06f5c4:v1
    // insert your protected definitions here
    // ev@d2d1847a-7b88-41dd-ad07-92785f06f5c4:v1

private:
    const Everest::PtrContainer<ExamplePublisher>& mod;
    const Conf& config;

    virtual void init() override;
    virtual void ready() override;

    // ev@3370e4dd-95f4-47a9-aaec-ea76f34a66c9:v1
    // insert your private definitions here
    std::thread publisher_thread;
    Everest::SteadyTimer steady_timer;
    // ev@3370e4dd-95f4-47a9-aaec-ea76f34a66c9:v1
};

// ev@3d7da0ad-02c2-493d-9920-0bbbd56b9876:v1
// insert other definitions here
// ev@3d7da0ad-02c2-493d-9920-0bbbd56b9876:v1

} // namespace example_pub
} // namespace module

#endif // EXAMPLE_PUB_EXAMPLE_PUBLISHER_IMPL_HPP
