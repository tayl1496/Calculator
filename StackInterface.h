/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  StackInterface class template definition.
 *
 *  Adapted from page 197 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 17 Sep 2018
 *
 *  @version 7.0 */

#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

/** @class StackInterface StackInterface.h "StackInterface.h"
 *
 *  Definition of StackInterface class template. */
template <typename ItemType>
class StackInterface {
 public:
  /** Virtual destructor. */
  virtual ~StackInterface() = default;

  /** Sees whether this stack is empty.
   *
   *  @return True if the stack is empty, or false. */
  virtual bool isEmpty() const = 0;

  /** Adds a new entry to the top of this stack.
   *
   *  @post If successful, newEntry is stored at the top of this
   *        stack.
   *
   *  @param newEntry The object to be added as a new entry.
   *
   *  @return True if addition was successful, or false. */
  virtual bool push(const ItemType& newEntry) = 0;

  /** Removes the top of this stack.
   *
   *  @post If successful, the top of this stack has been removed.
   *
   *  @return True if removal was successful, or false. */
  virtual bool pop() = 0;

  /** Retrieves the top of this stack.
   *
   *  @pre This stack is not empty.
   *
   *  @post None.
   *
   *  @return The top of this stack.
   *
   *  @throws PrecondViolatedExcep If the precondition is violated. */
  virtual ItemType peek() const = 0;
};

#endif
