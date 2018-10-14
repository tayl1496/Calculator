/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for an object thrown on violation of precondition.
 *
 *  Adapted from page 250 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 26 Sep 2018
 *
 *  @version 7.0 */

#ifndef DIVID_BY_ZERO_EXCEP_
#define DIVID_BY_ZERO_EXCEP_

#include <stdexcept>
#include <string>

/** @class DividByZeroExcep DividByZeroExcep.h "DividByZeroExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class DividByZeroExcep : public std::overflow_error {
 public:
  explicit DividByZeroExcep(const std::string& message = "");

  virtual ~DividByZeroExcep() noexcept = default; //throw();
};

#endif
