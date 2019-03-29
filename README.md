# Corewar42_VM
Virtual Machine for Corewar project at School 42

From the school subject:
  What is Corewar?<br>
    • Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one an- other with the support of “processes”, with the objective being for these champions to stay “alive”.<br>
    • The processes are executed sequentially within the same virtual machine and mem- ory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc...<br>
    • The game ends when all the processes are dead. The winner is the last player reported to be “alive”.<br>
<br>
  The virtual machine: It’s the “arena” in which your champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes; we are asking you for a gladiator fight, not a one-man show simulator.<br>
  
 "Make" to build the project.<br>
 Usage: ./corewar [-dump N] [-show flags][-a] [-n N] <champion1.cor> <...><br>
	-a		: Prints output from "aff" (Default is to hide it)<br>
	-d N		: Dumps memory after N cycles then exits<br>
  -n N    : Assigns a number to the player<br>
	-show flags	: Can be used together to enable several<br>
				- c : Show cycles<br>
				- d : Show death<br>
				- l : Show lives<br>
				- o : Show operations<br>
				- v : Show NCurses Visualization<br>
<br>
Inside the vm_champs folder you can find the assembler binary and original corewar bnary we had to (kind of) reverse-engineer.<br>
There are also different champions, valid or not, both in ./vm_champs and ./champs_for_defense folders.<br>
