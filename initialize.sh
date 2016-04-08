BUILDDIR="build";
BINDIR="bin";

cd src/
CDIRS=$(find -type d -printf '%d\t%P\n' | cut -f2-);
cd ..

# Create build folder if is not exists
if [[ ! -d $BUILDDIR ]]; then
	mkdir $BUILDDIR;
fi

# Create bin folder if is not exists
if [[ ! -d $BINDIR ]]; then
	mkdir $BINDIR;
fi

for i in $CDIRS; do
	
	DIR="${BUILDDIR}/${i}";

	# Create each folder if is not exists
	if [[ ! -d $DIR ]]; then
		mkdir $DIR;
	fi

done