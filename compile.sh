#!/bin/sh
 
tmp_pwd=`pwd`
cd /Applications/user-installed/QNX/Momentics.app && source bbndk-* && cd $tmp_pwd

PBHOSTARCH=arm-unknown-nto-qnx8.0.0eabi
PBBUILDARCH=x86_64-apple-darwin
PBTARGETARCH=arm-unknown-nto-qnx8.0.0eabi 
 
./configure --host=$PBHOSTARCH --build=$PBBUILDARCH --target=$PBTARGETARCH --with-ipc=tcp --prefix=$tmp_pwd/dest --program-transform-name=
make install
