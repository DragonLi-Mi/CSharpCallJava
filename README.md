# CSharpCallJava
C#  invoke Java via C++ as a wraper. 

C# invoke C++ via P/invoke. C++ starts a JVM to run the Java code.

C# code should be compiled in .NET core 2.0 

You should edit the Makefile to set the Path of Java SDK
export LD_LIBRARY_PATH=/usr/lib/jvm/java-1.9.0-openjdk-amd64/lib/amd64/server 
or add it into your enviroment
# Compile:
javac MyTest.java

make

dotnet build
