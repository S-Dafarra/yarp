/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_OS_WIRE_H
#define YARP_OS_WIRE_H

#include <yarp/os/PortReader.h>
#include <yarp/os/WireLink.h>

namespace yarp {
namespace os {

/**
 * Base class for IDL client/server.
 */
class Wire : public PortReader
{
private:
    WireLink _yarp_link;

public:
    /**
     *
     * Get YARP state associated with this object.
     *
     * @return state object.
     *
     */
    WireLink& yarp()
    {
        return _yarp_link;
    }
};

} // namespace os
} // namespace yarp

#endif // YARP_OS_WIRE_H
