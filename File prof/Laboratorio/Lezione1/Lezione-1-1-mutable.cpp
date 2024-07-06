struct Foo
{
	mutable int value; // mutable - permits modification of the class member declared mutable even if the containing object is declared const (es. si può scrivere "mutable const int* p;")
	int secondvalue;
};

int main()
{
	const struct Foo foo = { 10, 100 };
	foo.value = 200;
	//foo.secondvalue = 100; error
}