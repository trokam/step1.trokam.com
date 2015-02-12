/***********************************************************************
 *                            T R O K A M
 *                 Free and Open Source Search Engine
 *
 * Service        http://trokam.com/search
 * About          http://trokam.com/pages/about
 * Development    http://dev.trokam.com/
 * Repository     https://github.com/trokam
 * News           https://twitter.com/trokam
 *
 * Copyright (C) 2015, Nicolas Slusarenko
 *                     nicolas.slusarenko@trokam.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 **********************************************************************/

/// C
#include <stdlib.h>
#include <unistd.h>

/// C++
#include <iostream>

/// Trokam
#include "machine.h"
#include "converter.h"
#include "log.h"

/***********************************************************************
 *
 **********************************************************************/
std::string trokam::machine::hostname_pid()
{
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /// Get hostname
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    char hostname[1024];
    hostname[1023]= '\0';
    gethostname(hostname, 1023);
    std::string host(hostname);

    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /// Get pid
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int pid= getpid();

    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /// Generates a name for this feeder
    /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::string hp= host + "_" + converter::to_string(pid);

    LOG(DEBUG, "hostname_pid= " << hp);
    return hp;
}

/***********************************************************************
 *
 **********************************************************************/
void trokam::machine::mkdir(const std::string &directory)
{
    std::string command= "mkdir -p " + directory;
    system(command.c_str());
}

/***********************************************************************
 *
 **********************************************************************/
void trokam::machine::rm_dir(const std::string &path)
{
    std::string command= "rm -rf " + path;
    system(command.c_str());
}

/***********************************************************************
 *
 **********************************************************************/
void trokam::machine::rm_file(const std::string &file)
{
    std::string command= "rm -f " + file;
    system(command.c_str());
}
