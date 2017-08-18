#include <jni.h>
#include <iostream>
#include <cstdio>
using namespace std;
extern "C"{
int Invokejava(const char*  message)
{
       JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
       JNIEnv *env;                      // Pointer to native interface
           //================== prepare loading of Java VM ============================
       JavaVMInitArgs vm_args;                        // Initialization arguments
       JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
       options[0].optionString = "-Djava.class.path=.";   // where to find java .class
       vm_args.version = JNI_VERSION_1_6;             // minimum Java version
       vm_args.nOptions = 1;                          // number of options
       vm_args.options = options;
       vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
           //=============== load and initialize Java VM and JNI interface =============
       jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
       delete options;    // we then no longer need the initialisation options.
       if (rc != JNI_OK) {
              // TO DO: error processing...
             cin.get();
             exit(EXIT_FAILURE);
       }
          //=============== Display JVM version =======================================
       cout << "JVM load succeeded: Version ";
       jint ver = env->GetVersion();
       cout << ((ver>>16)&0x0f) << "."<<(ver&0x0f) << endl;
        jclass cls2 = env->FindClass("MyTest");
        if(cls2== nullptr){
        cerr<<"ERROR : class not find";
        }
        else{
           printf("%s",message);
            cout<<"Class MyTest found"<<endl;
            jmethodID mid= env->GetStaticMethodID(cls2,"sayHi","()V");
            if(mid==nullptr)
                cerr<<"ERROR : method void sayHi() not found!"<<endl;
            else{
            env->CallStaticVoidMethod(cls2,mid);
            }
        }
       jmethodID mid2 = env->GetStaticMethodID(cls2,"Square","(I)I");
        if(mid2==nullptr){
        cerr<<"ERROR: method Square(int) not find!"<<endl;
        }
        else{
            int i;
            cout<<"input a number"<<endl;
            cin>>i;
            cout<<"get Square return = "<< env->CallStaticIntMethod(cls2,mid2,(jint)i);
            cout<<endl;
        }
       // TO DO: add the code that will use JVM <============  (see next steps)

       jvm->DestroyJavaVM();
       cin.get();
       return 0;
}
}
