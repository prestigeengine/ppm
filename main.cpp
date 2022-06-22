#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <fstream>
using std::string;

/*
    (Huge Gay) Design Intrinsics I Thought Of While Reconsidering My Decisions In Hobbies And All That Bullshit
    Don't be afraid to implement new intrinsics! (or maybe be, since it's just being conceptualized still)

    * "doesnt it just fetch a package from a webserver" - warsaw
    * (They're right, you know)

    → Consider representing packages as objects, as they may get complicated later on.
    ```
    struct Package
    {
        string name;
        string version;
        size_t id;
        fstream package_file
        and maybe...
        string origin_url;
    }
    ```
    → GET PROJECT INTEGRATION GOING YOU DUMBASS!

   ┌─→ Consider project structure - To Project or not to Project, that is the question.
   ├-┬─→ how does ppm know what classifies as a project?
   │ ├-┬─→ Copy even further from other software you use (Git this time) - .pp/ directory, if it's there, it's a prestige project
   │ │ └-──→ To deal with dependencies, they're just placed inside such directory (lol)
   │ └─→ Or! Consider a prestige project format, Visual Studio vcxproj/sln XML style
   │
   └─┬─→ What about packages?
     ├───→ Fetch them from webserver
     ├-──→ Let the user install local files as well
     ├-┬─→ Will they be compressed in .zip or some other compression format?
     │ ├-──→ Yes, decompress them, if it's a custom format, store compression/decompression stuff elsewhere
     │ └-──→ No, just do copy/paste
     ├───→ Add project dependency to manifest (and an option to not do so, --no-manifest-changes)
     └───→ Option to update dependencies (ppm update-dependencies [project-root])
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

void doStuffWithPackage(string do_this, string with)
{
    if (do_this.compare("install") == 0) pkginstall(with);
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
    doStuffWithPackage(arg, target);

    cease();
}
