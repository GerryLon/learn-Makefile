
css_objects := index.min.css common.min.css


LESSC := ./node_modules/lessc/node_modules/.bin/lessc
PHONY =

PHONY += all
all: install compime-css


PHONY += install
install:
	cnpm i --save lessc \
	&& cnpm i --save less-plugin-clean-css


PHONY += compime-css
compime-css: $(css_objects)

%.min.css: %.css
	$(LESSC) --clean-css $< $@

%.css: %.less
	$(LESSC) $< $@

.PHONY: clean
PHONY  += clean
clean:
	rm -rf ./*.css && rm -rf ./node_modules

.PHONY: $(PHONY)
