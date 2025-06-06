// ======================================================================
// \title  StringArraySerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for StringArray struct
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "StringArraySerializableAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

StringArray ::
  StringArray() :
    Serializable(),
    m_s1(m___fprime_ac_s1_buffer, sizeof m___fprime_ac_s1_buffer, Fw::String(""))
{
  for (FwSizeType i = 0; i < 16; i++) {
    // Initialize the external string
    this->m_s2[i].setBuffer(&m___fprime_ac_s2_buffer[i][0], sizeof m___fprime_ac_s2_buffer[i]);
    // Set the array value
    this->m_s2[i] = Fw::String("");
  }
}

StringArray ::
  StringArray(
      const Fw::StringBase& s1,
      const Type_of_s2& s2
  ) :
    Serializable(),
    m_s1(m___fprime_ac_s1_buffer, sizeof m___fprime_ac_s1_buffer, s1)
{
  for (FwSizeType i = 0; i < 16; i++) {
    // Initialize the external string
    this->m_s2[i].setBuffer(&m___fprime_ac_s2_buffer[i][0], sizeof m___fprime_ac_s2_buffer[i]);
    // Set the array value
    this->m_s2[i] = s2[i];
  }
}

StringArray ::
  StringArray(const StringArray& obj) :
    Serializable(),
    m_s1(m___fprime_ac_s1_buffer, sizeof m___fprime_ac_s1_buffer, obj.m_s1)
{
  for (FwSizeType i = 0; i < 16; i++) {
    // Initialize the external string
    this->m_s2[i].setBuffer(&m___fprime_ac_s2_buffer[i][0], sizeof m___fprime_ac_s2_buffer[i]);
    // Set the array value
    this->m_s2[i] = obj.m_s2[i];
  }
}

StringArray ::
  StringArray(
      const Fw::StringBase& s1,
      const Fw::StringBase& s2
  ) :
    Serializable(),
    m_s1(m___fprime_ac_s1_buffer, sizeof m___fprime_ac_s1_buffer, s1)
{
  for (FwSizeType i = 0; i < 16; i++) {
    // Initialize the external string
    this->m_s2[i].setBuffer(&m___fprime_ac_s2_buffer[i][0], sizeof m___fprime_ac_s2_buffer[i]);
    // Set the array value
    this->m_s2[i] = s2;
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

StringArray& StringArray ::
  operator=(const StringArray& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_s1, obj.m_s2);
  return *this;
}

bool StringArray ::
  operator==(const StringArray& obj) const
{
  if (this == &obj) { return true; }

  // Compare non-array members
  if (!(this->m_s1 == obj.m_s1)) {
    return false;
  }

  // Compare array members
  for (FwSizeType i = 0; i < 16; i++) {
    if (!(this->m_s2[i] == obj.m_s2[i])) {
      return false;
    }
  }

  return true;
}

bool StringArray ::
  operator!=(const StringArray& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const StringArray& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus StringArray ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_s1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (FwSizeType i = 0; i < 16; i++) {
    status = buffer.serialize(this->m_s2[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

Fw::SerializeStatus StringArray ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_s1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (FwSizeType i = 0; i < 16; i++) {
    status = buffer.deserialize(this->m_s2[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void StringArray ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "s1 = %s, "
    "s2 = [ %s ]"
    " )";

  // Declare strings to hold any serializable toString() arguments
  Fw::String s2Str;

  // Call toString for arrays and serializable types
  for (FwSizeType i = 0; i < 16; i++) {
    Fw::String s2Tmp;
    s2Tmp = this->m_s2[i];

    FwSizeType size = s2Tmp.length() + (i > 0 ? 2 : 0);
    if ((size + s2Str.length()) <= s2Str.maxLength()) {
      if (i > 0) {
        s2Str += ", ";
      }
      s2Str += s2Tmp;
    } else {
      break;
    }
  }

  sb.format(
    formatString,
    this->m_s1.toChar(),
    s2Str.toChar()
  );
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void StringArray ::
  set(
      const Fw::StringBase& s1,
      const Type_of_s2& s2
  )
{
  this->m_s1 = s1;

  for (FwSizeType i = 0; i < 16; i++) {
    // Initialize the external string
    this->m_s2[i].setBuffer(&m___fprime_ac_s2_buffer[i][0], sizeof m___fprime_ac_s2_buffer[i]);
    // Set the array value
    this->m_s2[i] = s2[i];
  }
}

void StringArray ::
  sets1(const Fw::StringBase& s1)
{
  this->m_s1 = s1;
}

void StringArray ::
  sets2(const Type_of_s2& s2)
{
  for (FwSizeType i = 0; i < 16; i++) {
    this->m_s2[i] = s2[i];
  }
}
