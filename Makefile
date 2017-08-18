wraper.so:wraper.cpp 
	g++ -shared -o wraper.so  -L/usr/lib/jvm/java-1.9.0-openjdk-amd64/lib/amd64/server  -I/usr/lib/jvm/java-9-openjdk-amd64/include -I/usr/lib/jvm/java-9-openjdk-amd64/include/linux/  ./wraper.cpp -fPIC -ljvm
	export LD_LIBRARY_PATH=/usr/lib/jvm/java-1.9.0-openjdk-amd64/lib/amd64/server 
