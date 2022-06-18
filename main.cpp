#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>

const std::string ver = "v0.01";

void pkginstall(const char* pkg)
{
	// TODO: fetch from website
	std::fstream package(pkg, std::ios::out);
	if (!package)
	{
		std::cerr << "Failed to open package!\n";
		exit(1);
	}
	// TODO: deal with package properly
	package.close();
}

int printInstallHelp(void)
{
	std::cerr
		<< "PPM v0.01\n"
		<< "No package specified!"
		<< "Usage: ppm install <package>";
	return EXIT_FAILURE;
}

void do_stuff(std::string do_this, const char* with)
{
	if (do_this.compare("install")) pkginstall(with);
}

void cease() {}

int main(int count, const char* value[])
{
	if (count < 1) // no action specified
	{
		std::cerr << "PPM " << ver << "\nNo action specified!\n";
		exit(1);
	}

	if (strcmp(value[1], "version") == 0)
	{
		std::cout << "PPM " << ver;
		exit(0);
	}
	if (count < 3) // no thing to mess with!
	{
		if (strcmp(value[1], "install") == 0)
		{
			std::cerr
				<< "PPM " << ver
				<< "\nNo package specified!"
				<< "\nUsage: ppm install <package>"
				<< std::endl;
		}
		exit(1);
	}
	do_stuff(value[1], value[2]);

	cease();
}
