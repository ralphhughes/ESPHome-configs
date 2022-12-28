#!/bin/bash
# echo "Starting Python3 venv. Once finished with ESPHome, type 'deactivate' to quit"
if [[ "$0" = "$BASH_SOURCE" ]]; then
    echo "Needs to be run using: $ source start-esphome-venv.sh"

else
    VENVPATH="venv/bin/activate"
    if [[ $# -eq 1 ]]; then 
        if [ -d $1 ]; then
            VENVPATH="$1/bin/activate"
        else
            echo "Virtual environment $1 not found"
            return
        fi

    elif [ -d "venv" ]; then 
        VENVPATH="venv/bin/activate"

    elif [-d "env"]; then 
        VENVPATH="env/bin/activate"
    fi

    echo "Activating virtual environment $VENVPATH, type 'deactivate' to quit"
    source "$VENVPATH"
fi

# Putting this in a script does nothing:
# source venv/bin/activate
