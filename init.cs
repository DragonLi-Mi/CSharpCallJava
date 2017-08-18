using System;
using System.Runtime.InteropServices;
namespace invoke
{
    class Program
    {
        [DllImport("libc.so.6")]
         private static extern int getpid();
		 // You should edit the path of you .so lib
        [DllImport("./wraper.so",EntryPoint="Invokejava")]
         private static extern int Invokejava(string message);

        static void Main(string[] args)
        {
         int pid= getpid();
         Console.WriteLine(pid);
            Console.WriteLine("Hello World!");
            int status= Invokejava("Hi C# to cpp");
            Console.WriteLine(status);
    
        }
    }
}
