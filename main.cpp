#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <fstream>
using std::string;

/*
	(Huge Gay) Design Intrinsics I Thought Of While Reconsidering My Decisions In Hobbies And All That Bullshit

	- Have you ever considered OOP? <- gay
	- "doesnt it just fetch a package from a webserver" - warsaw
	- (They're right, you know)
*/

const string ver = "v0.01"; // const because it will never get past this version

void pkginstall(string pkg)
{
	// TODO: fetch from website
	std::fstream package(pkg, std::ios::out);
	if (!package)
	{
		std::cerr << "Failed to open package!\n";
		exit(EXIT_FAILURE);
	}
	// TODO: deal with package properly
	// Do code generation, deal with package manifest
	// then integrate into project (somehow)
	package.close();
}

void do_stuff(string do_this, string with)
{
	if (do_this.compare("install")) pkginstall(with);
}

void cease(void) {}

int main(int count, const char* value[])
{
	if (count < 2) // no action specified
	{
		std::cout << "PPM " << ver << "\nNo action specified!\n";
		exit(EXIT_FAILURE);
	}

	string arg = value[1];

	if (arg.compare("version") == 0)
	{
		std::cout << "PPM " << ver;
		exit(EXIT_SUCCESS);
	}
	if (count < 3) // no thing to mess with!
	{
		if (arg.compare("install") == 0)
		{
			std::cerr
				<< "PPM " << ver
				<< "\nNo package specified!"
				<< "\nUsage: ppm install <package>"
				<< std::endl;
		}
		exit(EXIT_FAILURE);
	}
	string target = value[2];
	do_stuff(arg, target);

	cease();
}
