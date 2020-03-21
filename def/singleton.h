/*
*   2020/3/21 created by oliver
*   copyright for oliver
*/

#pragma once

/* initialise singleton pointer, called by programmer */
#define InitialiseSingleton(T) \
    template<> T * CSingleton<T>::m_singleton = nullptr

/* create a file_scoped singleton object. GetInstance()*/
#define CreateFileSingleton(T)\
    InitialiseSingleton(T);\
    T body##T

template <typename T>
class CSingleton
{
public:
    virtual ~CSingleton()
    {
        m_singleton = nullptr;
    }

    inline static T* GetInstance()
    {
        if (m_singleton == nullptr)
        {
            m_singleton = new T();
        }
        return m_singleton;
    }

    inline static void SetInstance(T *other)
    {
        m_singleton = other;
    }

    inline static void Destroy()
    {
        if (m_singleton) 
        {
            delete m_singleton;
            m_singleton = nullptr;
        }
    }
    
protected:
    CSingleton() = default;

protected:
    static T* m_singleton;

};

