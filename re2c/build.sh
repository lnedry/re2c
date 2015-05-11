#!/bin/sh

builddir=.build
rm -rf $builddir
mkdir $builddir

cd $builddir
../configure --enable-silent-rules && \
make bootstrap -j5
cd ..