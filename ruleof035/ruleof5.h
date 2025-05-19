class Asliceable {
    protected:
        int a; 
    public:
        Asliceable() = default;
        ~Asliceable() = default;
        Asliceable(const Asliceable&) = default;
        Asliceable& operator=(const Asliceable&) = default;
        Asliceable(Asliceable&&) noexcept = default;
        Asliceable& operator=(Asliceable&&) noexcept = default;

        virtual int val(){ return a;}
        void setval(int in){ a=in; };
};


class B : public Asliceable {
    public:
        int val() { return (-1*a); }
}; 