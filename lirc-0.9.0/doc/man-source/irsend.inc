[NAME]
irsend - basic LIRC program to send infra-red commands

[DESCRIPTION]
Asks the \fBlircd\fR daemon to send one or more CIR
(Consumer Infra-Red) commands. This is intended for remote control
of electronic devices such as TV boxes, HiFi sets, etc.
.PP
\fIDIRECTIVE\fR can be:
.nf
.RS 3
\fBSEND_ONCE\fR         - send \fICODE\fR [\fICODE\fR ...] once
\fBSEND_START\fR        - start repeating \fICODE\fR
\fBSEND_STOP\fR         - stop repeating \fICODE\fR
\fBLIST\fR              - list configured remote items
\fBSET_TRANSMITTERS\fR  - set transmitters \fINUM\fR [\fINUM\fR ...]
\fBSIMULATE\fR          - simulate IR event
.RE
.fi

.PP 
\fIREMOTE\fR is the name of a remote, as described in the \fBlircd\fR
configuration file.

.PP
\fICODE\fR is the name of a remote control key of \fIREMOTE\fR, as it
appears in the \fBlircd\fR configuration file.

.PP
\fINUM\fR is the transmitter number of the hardware device. 

.PP
For the \fBLIST\fR \fIDIRECTIVE\fR, \fIREMOTE\fR and/or \fICODE\fR
can be empty:

.nf
.RS 3
\fBLIST\fR   ""    ""   - list all configured remote names
\fBLIST\fR \fIREMOTE\fR  ""   - list all codes of \fIREMOTE\fR
\fBLIST\fR \fIREMOTE\fR \fICODE\fR  - list only \fICODE\fR of \fIREMOTE\fR
.RE
.fi

.PP
The \fBSIMULATE\fR command only works if it has been explicitly
enabled in lircd.

[EXAMPLES]
.nf
.RS 3
irsend LIST DenonTuner ""
irsend SEND_ONCE  DenonTuner PROG\-SCAN 
irsend SEND_ONCE  OnkyoAmpli VOL\-UP VOL\-UP VOL\-UP VOL\-UP
irsend SEND_START OnkyoAmpli VOL\-DOWN ; sleep 3
irsend SEND_STOP  OnkyoAmpli VOL\-DOWN
irsend SET_TRANSMITTERS 1
irsend SET_TRANSMITTERS 1 3 4
irsend SIMULATE "0000000000000476 00 OK TECHNISAT_ST3004S"
.RE
.fi
[FILES]
.TP
.I /etc/lirc/lircd.conf
Default \fBlircd\fR configuration file.  It should contain all the
remotes, their infra-red codes and the corresponding timing and 
waveform details.

.SH DIAGNOSTICS
If \fBlircd\fR is not running (or /var/run/lirc/lircd lacks write
permissions) \fBirsend\fR aborts with the following diagnostics:
.nf
"irsend: could not connect to socket"
"irsend: Connection refused" (or "Permission denied").
.fi

[SEE ALSO]
.BR lircd "(8), " mode2 "(1), " smode2 "(1), " xmode2 "(1), " 
.BR irrecord "(1), " irw "(1), " http://www.lirc.org .