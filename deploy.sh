#!/bin/bash

if [ -z "$1" ]
  then
    echo "No project specified"
    echo "Usage [project-folder] [device-id] [device-type 'e' for electron or 'p' for proton]"
    exit 1
fi

if [ -z "$2" ]
  then
    echo "No device id specified"
    echo "Usage [project-folder] [device-id] [device-type 'e' for electron or 'p' for proton]"
    exit 1
fi

if [ -z "$3" ]
  then
    echo "No device type, specify 'e' or 'p'"
    echo "Usage [project-folder] [device-id] [device-type 'e' for electron or 'p' for proton]"
    exit 1
fi

echo "Compiling project: $1"
echo "Device id: $2"

if [ -d "$1" ]; then
  cd $1
  particle compile $3

  file="$(ls $3_*)"

  echo "Flashing ${file} into device $2"
  particle flash $2 "${file}"

  rm -f "${file}"
  echo "Deleted file ${file}"
else
  echo "Directory does not exist"
fi
