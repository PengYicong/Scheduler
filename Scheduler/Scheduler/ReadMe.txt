========================================================================
    CONSOLE APPLICATION : Scheduler Project Overview
========================================================================

AppWizard has created this Scheduler application for you.

This file contains a summary of what you will find in each of the files that
make up your Scheduler application.


Scheduler.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Scheduler.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Scheduler.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Scheduler.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////

Scheduler.cpp is the interface of this project.

The cluster initialize file "Cluster.txt" is located under the Debug folder.
Modification to the code is needed if the environment changes.
*******
Line 36 of the file ScheduleManager.cpp the file path should be modified accordingly.
*******
The initialization information is in the format of <number of host> <memory per host> <cores per host>
For example:
4 1000 10
means 4 host in total with 1000 memory space and 10 cores per host
You may modify it as needed.

Request input to the program should be in the format of:
[string]<Name> [float]<Core Required> [float]<Memory Required> [int]<Time Required> [int]<Number of Instances>
For example:
Job1 2 10 10 3 means Job1 needs 2 cores 10 memory space takes up 10 seconds to finish and should be running 3 instances.
Especially:
if the name of the request is "EXIT" and followd by arbitrary valid numbers the program will exit.
For example:
EXIT 2 10 2 1