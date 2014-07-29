# Rr3

## Dependency

### OS X

    brew install r3

### Ubuntu PPA

The PPA for libr3 can be found in https://launchpad.net/~r3-team/+archive/libr3-daily

## Installation

    $ gem install rr3

## Usage

```ruby
t = Rr3::Tree.new 10
t.insert_path "/foo/bar"
t.compile!
t.match "/foo/bar"  # => true
t.match "/foo/barr" # => false
t.dump 0
```