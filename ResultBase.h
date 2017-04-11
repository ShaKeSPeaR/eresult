/** ***************************************************************************
 * \file
 * \brief Шаблонный базовый класс для результатов операций
 * \author Спирин А.Д.
 *
 *****************************************************************************/
#ifndef _RESULTBASE_H
#define _RESULTBASE_H

#include <cstdint>


/**
 * \brief Base templated class for operation result
 *
 * \tparam CodeT operation code type
 * \tparam OkCode code for 'OK' value (uses in operator bool())
 * \tparam StrT string type for description
 *
 * Full template realization for operation results .
 * Have full stack for operators + operators for equality check and conversions
 */
template<typename CodeT, CodeT OkCode, typename StrT>
class ResultBase
{
public:

    using code_type   = CodeT; ///< internal code type
    using string_type = StrT;  ///< internal string type
    static const NoErrorCode = OkCode ///< No error code

    ///Simple constructor with code
    explicit ResultBase(CodeT code): m_code(code) {}

    /**
     * \brief Templated universal constructor with code and description
     * \tparam CT any type with conversion to code_type
     * \tparam ST any type with conversion to string_type
     * \param[in] code universal reference to code
     * \param[in] descr universal reference to description
     */
    template<typename CT, typename ST>
    ResultBase(CT&& code, ST&& descr)
        : m_code(std::forward<CT>(code)),
          m_description(std::forward<ST>(descr))
    {}

    ResultBase()                             = default;
    ResultBase(const ResultBase&)            = default;
    ResultBase(ResultBase&&)                 = default;
    ResultBase& operator=(const ResultBase&) = default;
    ResultBase& operator=(ResultBase&&)      = default;

    ///compare two results by ==
    inline bool operator == (const ResultBase<CodeT, OkCode, StrT>& res) const
    {
        return m_code == res.m_code;
    }
    ///compare two results by !=
    inline bool operator != (const ResultBase<CodeT, OkCode, StrT>& res) const
    {
        return m_code != res.m_code;
    }
    ///compare results with code by ==
    inline bool operator == (const code_type& code) const
    {
        return m_code == code;
    }
    ///compare results with code by !=
    inline bool operator != (const code_type& code) const
    {
        return m_code != code;
    }
    ///conversion to bool (compare code with OkCode)
    explicit operator bool()
    {
        return m_code == NoErrorCode;
    }

    ///conversion to string
    explicit operator string_type()
    {
        return m_description;
    }
    ///conversion to int (convert code)
    explicit operator int()
    {
        return static_cast<int>(m_code);
    }

    ///replace code with stream operator
    inline ResultBase& operator << (const code_type& code)
    {
        m_code = code;
        return *this;
    }
    ///replace description with stream operator
    inline ResultBase& operator << (const string_type& descr)
    {
        m_description = descr;
        return *this;
    }
    ///update description (by adding to existing one)
    inline ResultBase& operator += (const string_type& descr)
    {
        m_description += descr;
        return *this;
    }

    ///get result code
    inline code_type          code()  const { return m_code; }
    ///get result description
    inline const string_type& descr() const { return m_description; }
    ///get result description (std style)
    inline string_type        str()   const { return m_description; }

private:
    code_type   m_code;         ///< result code
    string_type m_description;  ///< code description
};


#endif
