#ifndef LEARNING_OPTIONAL_H_
#define LEARNING_OPTIONAL_H_

#include <type_traits>
#include <memory>
#include <cassert>

template<typename T>
struct optional_base
{
  optional_base()
    : value_(nullptr)
  {

  }

  optional_base(nullptr_t)
    : value_(nullptr)
  {

  }

  optional_base(optional_base&& another)
    : value_(std::move(another.value_))
  {

  }

  optional_base& operator=(optional_base<T>&& another)
  {
    value_ = std::move(another.value_);
    return *this;
  }

  operator bool() const {
    return has_value();
  }

  bool has_value() const {
    if (value_) {
      return true;
    }
    else {
      return false;
    }
  }

  T& value() {
    assert(value_);
    return *value_;
  }

  const T& value() const {
    assert(value_);
    return *value_;
  }

protected:
  std::unique_ptr<T> value_;
};

template<typename T>
class optional_copyable : public optional_base<T>
{
public:
  optional_copyable()
    : optional_base<T>()
  {

  }

  optional_copyable(nullptr_t)
    : optional_base<T>(nullptr)
  {

  }

  optional_copyable(const optional_copyable& another)
    : optional_base<T>(nullptr)
  {
    if (another.has_value()) {
      this->value_ = std::make_unique<T>(another.value());
    }
  }
  
  optional_copyable& operator=(const optional_copyable& another)
  {
    if (this == &another) {
      return *this;
    }
    if (!another.has_value()) {
      this->value_.reset();
    }
    else if (another.has_value() && this.has_value()) {
      *(this.value_) = *(another.value_);
    }
    else {
      this.value_ = std::make_unique<T>(*(another.value_));
    }
    return *this;
  }
  
  optional_copyable(const T& value)
    : optional_base(nullptr)
  {
    if (this.has_value()) {
      *(this.value_) = value;
    }
    else {
      this.value_ = std::make_unique<T>(value);
    }
  }

  optional_copyable& operator=(const T& another)
  {
    if (this->has_value()) {
      *(this->value_) = another;
    }
    else {
      this->value_ = std::make_unique<T>(another);
    }
    return *this;
  }
};

template<typename T>
using optional =
typename std::conditional<
  std::is_copy_assignable<T>::value && std::is_copy_constructible<T>::value,
  optional_copyable<T>,
  optional_base<T>
>::type;

#endif // LEARNING_OPTIONAL_H_