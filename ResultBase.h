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
 * \brief Базовый шаблонный класс для результатов операций
 *
 * \tparam CodeT тип кода ошибки
 * \tparam OkCode конкретной ошибкой для ОК кода (используется для operator bool)
 * \tparam StrT тип строки для описания результата
 *
 * Полная шаблонная реализация класса для возвращение результатов.
 * Также имеет полный набор операторов и методов для сравнения и обработки.
 */
template<typename CodeT, CodeT OkCode, typename StrT>
class ResultBase
{
public:

    using code_type   = CodeT; ///< Внутренний тип кода
    using string_type = StrT;  ///< Внутренний тип строки

    ///Простой конструктор к кодом без текста
    ResultBase(CodeT code): m_code(code) {}

    /**
     * \brief Шаблонный универсальный конструктор с кодом и строкой
     * \tparam CT любой тип, который может быть преобразован в code_type
     * \tparam ST любой тип, который может быть преобразован в string_type
     * \param[in] code универсальная ссылка с кодом результата
     * \param[in] descr универсальная ссылка с текстом ошибки
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

    ///оператор сравнения двух результатов на ==
    inline bool operator == (const ResultBase<CodeT, OkCode, StrT>& res) const
    {
        return m_code == res.m_code;
    }
    ///оператор сравнения двух результатов на !=
    inline bool operator != (const ResultBase<CodeT, OkCode, StrT>& res) const
    {
        return m_code != res.m_code;
    }
    ///оператор сравнения результата с заданным кодом на ==
    inline bool operator == (const code_type& code) const
    {
        return m_code == code;
    }
    ///оператор сравнения результата с заданным кодом на !=
    inline bool operator != (const code_type& code) const
    {
        return m_code != code;
    }
    ///оператор приведения к bool (сравнивает что есть внутри с OkCode)
    explicit operator bool()
    {
        return m_code == OkCode;
    }

    ///оператор приведения к строке
    explicit operator string_type()
    {
        return m_description;
    }
    ///оператор приведения к int (преобразовывает код)
    explicit operator int()
    {
        return static_cast<int>(m_code);
    }

    ///запись кода в результат через потоковый оператор
    inline ResultBase& operator << (const code_type& code)
    {
        m_code = code;
        return *this;
    }
    ///запись строки в результат через потоковый оператор
    inline ResultBase& operator << (const string_type& descr)
    {
        m_description = descr;
        return *this;
    }
    ///добавление строки описания к уже существующей
    inline ResultBase& operator += (const string_type& descr)
    {
        m_description += descr;
        return *this;
    }

    ///вернуть код ошибки
    inline code_type          code()  const { return m_code; }
    ///вернуть описание ошибки
    inline const string_type& descr() const { return m_description; }
    ///вернуть описание ошибки (подходит для std)
    inline string_type        str()   const { return m_description; }

private:
    code_type   m_code;         ///< код ошибки
    string_type m_description;  ///< описание ошибки
};


#endif
