class demo
{
private:
public:
demo(int, int );//PC
~demo()=default;
demo()=default;
demo(const demo&)=delete;
demo(demo&&)=delete;
demo operator=(const demo&)=delete;
demo operator=(demo&&)=delete;
};