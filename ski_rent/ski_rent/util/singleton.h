#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
class Singleton {
public:
    static T* instance() {
        static T* _instance = 0;

        if (!_instance) {
            _instance = new T();
        }

        return _instance;
    }

protected:
    Singleton() {}
    ~Singleton() {}
};

#endif // SINGLETON_H
