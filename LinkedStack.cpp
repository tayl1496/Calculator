/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  stack.
 *
 *  Adapted from pages 246-8 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 26 Sep 2018
 *
 *  @version 7.0 */

//#define NDEBUG

#include <new>

#include <cassert>

template <typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {

  if (!aStack.topPtr) {
    topPtr = nullptr;
  }
  else {
    NodePtr origChainPtr(aStack.topPtr);

    try {
      topPtr = new Node<ItemType>(origChainPtr->getItem() );

      NodePtr newChainPtr(topPtr);

      origChainPtr = origChainPtr->getNext();

      while (origChainPtr) {
	newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()) );

	newChainPtr = newChainPtr->getNext();
	origChainPtr = origChainPtr->getNext();
      }
    }
    catch (const std::bad_alloc&) {
      while (!isEmpty() ) {
	pop();
      }
      throw;
    }
  }
}

template <typename ItemType>
LinkedStack<ItemType>::~LinkedStack() {

  while (!isEmpty() ) {
    pop();
  }
}

template <typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const {

  return !topPtr;
}

template <typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {

  bool canPush(true);

  try {
    topPtr = new Node<ItemType>(newItem,
				topPtr);
  }
  catch (const std::bad_alloc&) {
    canPush = false;
  }

  return canPush;
}

template <typename ItemType>
bool LinkedStack<ItemType>::pop() {

  bool canPop(!isEmpty() );

  if (canPop) {
    NodePtr nodeToDeletePtr(topPtr);

    topPtr = topPtr->getNext();

    delete nodeToDeletePtr;
  }

  return canPop;
}

template <typename ItemType>
ItemType LinkedStack<ItemType>::peek() const {

  assert(!isEmpty() );

  return topPtr->getItem();
}
