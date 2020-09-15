#!/usr/bin/env perl

use Server;

$server = Server -> new('192.168.43.165', 'grumbly');
$server -> ping('192.168.43.250')
