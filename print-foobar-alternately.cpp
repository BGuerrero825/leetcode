class FooBar {
private:
    int n;
    int fb = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            if(fb == 0){
        	    // printFoo() outputs "foo". Do not change or remove this line.
        	    printFoo();
                fb = 1;
            } else { i--; }
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            if(fb == 1){
        	    // printBar() outputs "bar". Do not change or remove this line.
        	    printBar();
                fb = 0;
            } else { i--; }
        }
    }
};

