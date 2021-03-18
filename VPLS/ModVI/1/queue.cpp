#include "queue.h"

struct Node
{
  int key;
  Node *next;
};

Queue::Queue()
{
  // TODO
  this->front_ = nullptr;
  this->back_ = nullptr;
}

void Queue::push(int k)
{
  // TODO
  Node *new_node = new Node;
  new_node->key = k;
  new_node->next = nullptr;

  if (this->count() == 0)
  {
    this->front_ = new_node;
  }
  else
  {
    this->back_->next = new_node;
  }

  this->back_ = new_node;
}

void Queue::pop()
{
  // TODO
  if (this->count() == 0)
    throw EmptyException();

  Node *new_front = this->front_->next;
  delete this->front_;
  this->front_ = new_front;
}

int Queue::front() const
{
  // TODO
  if (this->count() == 0)
    throw EmptyException();

  return this->front_->key;
}

int Queue::back() const
{
  // TODO
  if (this->count() == 0)
    throw EmptyException();

  return this->back_->key;
}

int Queue::count() const
{
  // TODO
  int count = 0;

  Node *current = this->front_;
  while (current != nullptr)
  {
    count++;
    current = current->next;
  }
  return count;
}