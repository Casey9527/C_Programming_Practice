#!/bin/sh

print_your_name(){
	echo "My name is Casey Chen"
}

print_switch_ports() {
	echo "=xx eth1 eth1 1 port1"
	echo "=xx eth1 eth1 2 port2"
	echo "=xx eth1 eth1 3 port3"
	echo "=xx eth1 eth1 4 port4"
	echo "=xx eth0 eth0 5 eth0"
}

func=$1
$func $@
