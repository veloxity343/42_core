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
A software emulation of a physical computer that operates and behaves like a separate computer system within another physical machine. Essentially, it's a self-contained operating environment that behaves as if it's a separate computer, but it's actually running on a host computer. So you may ask the time-honoured Matrix question, is the VM blue-pilled, or red-pilled? Well, short and simple answer is that it is blue-pilled, remaining in the Matrix and unaware of the real world (the host computer). But since some VMs have exposure to the hypervisor and is thus able to retrieve information about its environment, the VM could, in essence, dodge bullets.

### Aptitude vs APT
#### Aptitude
- A high-level package manager.
- "Smarter" and will automatically remove unused packages or suggest installation of dependent packages.
#### APT 
- A lower level which can be used by other higher level package managers
- Will only do explicitly what it is told to do in the command line

### What is AppArmor?
A Linux security system that provides Mandatory Access Control (MAC) security. Allows the system admin to restrict the actions that processes can perform. It is included by default with Debian. Run aa-status to check if it is running.

### Password policy
For the password rules, we use the password quality checking library and there are two files the common-password file which sets the rules like upper and lower case characters, duplicate characters etc and the login.defs file which stores the password expiration rules (30 days etc). <code>sudo vi /etc/login.defs</code> <code>sudo vi /etc/pam.d/common-password</code>

### What is LVM?
Logical Volume Manager – allows us to easily manipulate the partitions or logical volume on a storage device. It is a method of managing disk drives on Unix-like operating systems. It allows for more flexible disk management by abstracting the physical storage devices into logical volumes, which can then be resized and moved around without disrupting the data stored on them.

### UFW (Uncomplicated Firewall)
A user-friendly command-line utility for managing iptables, the default firewall management tool in Linux. UFW provides a simplified interface for configuring firewall rules and managing network traffic on a Linux system. You use it to configure which ports to allow connections to and which ports to close. This is useful in conjunction with SSH, can set a specific port for it to work with.

### SSH
SSH or Secure Shell is an authentication mechanism between a client and a host. It uses encryption techniques so that all communication between clients and hosts is done in encrypted form. User on Mac or Linux can use SSH the terminal to work on their server via SSH.

### Cron
Cron or cron job is a command line utility to schedule commands or scripts to happen at specific intervals or a specific time each day. Useful if you want to set your server to restart at a specific time each day.
- <code>cd /usr/local/bin</code> – to show monitoring.sh
- <code>sudo crontab -u root -e</code> – to edit the cron job

### Commands
<ul dir="auto">
<li><code>sudo ufw status</code></li>
<li><code>sudo systemctl status ssh</code></li>
<li><code>getent group sudo</code></li>
<li><code>getent group user42</code></li>
<li><code>sudo adduser new username</code></li>
<li><code>sudo groupadd groupname</code></li>
<li><code>sudo usermod -aG groupname username</code></li>
<li><code>sudo chage -l username</code> - check password expire rules</li>
<li><code>hostnamectl</code></li>
<li><code>hostnamectl set-hostname new_hostname</code> - to change the current hostname</li>
<li>Restart your Virtual Machine.</li>
<li><code>sudo vi /etc/hosts</code> - change current hostname to new hostname</li>
<li><code>lsblk</code> to display the partitions</li>
<li><code>dpkg -l | grep sudo –</code> to show that sudo is installed</li>
<li><code>sudo ufw status numbered</code></li>
<li><code>sudo ufw allow port-id</code></li>
<li><code>sudo ufw delete rule number</code></li>
<li><code>ssh user_id@ip_address -p 4242</code> -  do this in terminal to show that SSH to port 4242 is working</li>
</ul>

### Bonus
I chose to install File Transfer Protocol (FTP) as it enables the transfer of files back and forth between computers or through the cloud, essentially functioning as a backup system. 

I installed lighttpp, a server which allows the delivery of web content to sites. Configuration was as simple as allowing port 80 in UFW. Next, MariaDB, which is a MySQL relational database management system. <code>mariadb -u <username-2> -p</code> Finally, PHP and Wordpress for web development to reference my database. 

Last but not least, I installed and configured FTP to connect into a root folder in my VM from a terminal, which allows restricted external manipulation without having to run the VM. 
