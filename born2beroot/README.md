## Born2BeRoot Evaluation

### Why Debian?
First and foremost, it is easy to use and stable. That it is free is also a large point in its favour. Additionally, it runs on numerous architectures and devices, as evidenced by my implementation of B2BR on Arm architecture. 

### Difference between Debian and Rocky
#### Debian
- Follows a release cycle characterised by its stability and predictability.
- New releases are made when the stable branch is considered ready for release, and is easily upgraded.
- It supports many libraries, filesystems and architectures.
- It uses apt-get as its package manager.
- Plenty of packages. 
- Typically used for customisation. 
#### Rocky
- Provides regular point releases that include security updates and bug fixes
- It is not so easily upgraded from older versions of CentOS.
- It does not support as many architectures.
- It uses YUM as its package manager.
- Limited packages
- Typically used for enterprise.

### What is a VM?
A software emulation of a physical computer that operates and behaves like a separate computer system within another physical machine. Essentially, it's a self-contained operating environment that behaves as if it's a separate computer, but it's actually running on a host computer. So you may ask the time-honoured Matrix question, is the VM blue-pilled, or red-pilled? Well, short and simple answer is that it is blue-pilled, remaining in the Matrix and unaware of the real world (the host computer). But since some VMs have exposure to the hypervisor and is thus able to retrieve information about its environment.

### Aptitude vs APT
#### Aptitude
- A high-level package manager.
- "Smarter" and will automatically remove unused packages or suggest installation of dependent packages.
#### APT 
- A lower level which can be used by other higher level package managers
- Will only do explicitly what it is told to do in the command line


