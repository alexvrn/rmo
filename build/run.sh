#!/bin/bash
# Версия Qt можно проверить так: qmake -v

# Копирование конфигурационного файла. если его нет
name="$(whoami)"
conf="/home/$name/.config/SAMI_DVO_RAN/rmo.conf"
if [ ! -f "$conf" ]; then
    echo "Конфигурационный файл скопирован"
    mkdir /home/$name/.config/SAMI_DVO_RAN
    cp ../rmo.conf $conf
fi

# Сборка
qmake ../
make