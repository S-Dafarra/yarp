// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2007 Freyr Magnusson
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
 *
 */
#ifndef DUMMYCONNECTOR_H
#define DUMMYCONNECTOR_H

#include <yarp/os/ConnectionReader.h>
#include <yarp/os/ConnectionWriter.h>

namespace yarp {
    namespace os {
        class DummyConnector;
    }
}

/**
 * \class DummyConnector
 * \brief A dummy connection to test yarp::os::Portable implementations
 * This class provides simple means to test read and write methods of the Portable interface.
 * 
 * Psudocode for a test should look something like this:
 *  - DummyConnector dummy; // create new connection with textmode=false
 *  - PortableObject object;
 *  - ... // set object values
 *  - object.write(dummy.getWriter()); // this will reset the connection and then write to it
 *  - PortableObject newObject;
 *  - newObject.read(dummy.getReader()); // this will write from the connection to the new object
 *  - ... // assert newObject values
 * 
 * \sa Portable BufferedConnectionWriter StreamConnectionReader StringInputStream Route
 *
 * \author Freyr Magnusson
 *
 */
class yarp::os::DummyConnector {
public:
    /**
     * Default constructor. TextMode set to false.
     */
    DummyConnector();


    /**
     * Destructor.
     */
    virtual ~DummyConnector();

    /**
     * Set the textMode of the dummy connection
     * \param textmode new textmode value
     */
    void setTextMode(bool textmode);

    /**
     * Get a clean/empty dummy ConnectionWriter. This will reset the connection each time.
     * \return a empty dummy ConnectionWriter
     * \sa ConnectionWriter Portable
     */
    ConnectionWriter& getCleanWriter();

    /**
     * Get the dummy ConnectionWriter loaded with whatever was written the ConnectionWriter since
     * it was last reset.
     * \return the current ConnectionWriter
     * \sa ConnectionWriter Portable
     */
    ConnectionWriter& getWriter();

    /**
     * Get the dummy ConnectionReader loaded with whatever was written the ConnectionWriter since
     * it was last reset.
     * \return a loaded ConnectionReader if it was previously written to
     * \sa ConnectionReader Portable
     */
    ConnectionReader& getReader();

    /**
     * Reset and clear the current ConnectionWriter
     */
    void reset();

private:
    void *implementation;
};


#endif
