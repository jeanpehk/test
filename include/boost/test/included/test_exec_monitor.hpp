//  (C) Copyright Gennadiy Rozental 2001-2003.
//  Permission to copy, use, modify, sell and distribute this software
//  is granted provided this copyright notice appears in all copies.
//  This software is provided "as is" without express or implied warranty,
//  and with no claim as to its suitability for any purpose.

//  See http://www.boost.org for most recent version including documentation.
//
//  File        : $RCSfile$
//
//  Version     : $Revision$
//
//  Description : included (vs. linked) version of Test Execution Monitor
// ***************************************************************************

#ifndef BOOST_INCLUDED_TEST_EXEC_MONITOR_HPP
#define BOOST_INCLUDED_TEST_EXEC_MONITOR_HPP

#include <boost/test/detail/unit_test_config.hpp> //!! for borland workaround
#include <libs/test/src/execution_monitor.cpp>

#include <libs/test/src/test_tools.cpp>

#include <libs/test/src/unit_test_result.cpp>
#include <libs/test/src/unit_test_suite.cpp>
#include <libs/test/src/unit_test_parameters.cpp>
#include <libs/test/src/unit_test_log.cpp>
#include <libs/test/src/unit_test_monitor.cpp>
#include <libs/test/src/supplied_log_formatters.cpp>

#include <libs/test/src/test_main.cpp>

// ***************************************************************************
//  Revision History :
//  
//  $Log$
//  Revision 1.4  2003/07/02 09:15:57  rogeeff
//  move log formatter in public interface
//
//  Revision 1.3  2003/06/09 08:40:00  rogeeff
//  1.30.beta1
//

// ***************************************************************************

#endif // BOOST_INCLUDED_TEST_EXEC_MONITOR_HPP
