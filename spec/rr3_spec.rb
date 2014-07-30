$: << File.expand_path('../../ext', __FILE__)
require 'spec_helper'

describe Rr3 do
  before(:all)do
    @tree = Rr3::Tree.new(10)
    @tree.insert_path "/bar"
    @tree.insert_path "/zoo", "test"
    @tree.insert_path "/foo/bar", a: 1
    @tree.insert_path "/post/{id}", [1]
    class A; attr_accessor :bar; end;
    @tree.insert_path "/user/{id:\\d+}", A.new.tap{|a| a.bar = 1}
    @tree.compile!
  end

  it 'matches' do
    expect(@tree.match("/bar")).to be_nil
    expect(@tree.match("/zoo")).to eql "test"
    expect(@tree.match("/foo/bar")).to eql a: 1
    expect(@tree.match("/post/1234")).to eql [1]
    expect(@tree.match("/user/1234").bar).to eql 1
    expect(@tree.match("/user/xxx")).to eql false
    expect(@tree.match("/asd")).to eql false
  end

  it 'dumps' do
    expect{ @tree.dump(0) }.not_to raise_error
  end

  it 'should returns root node' do
    expect(@tree.root).to be_a Rr3::Node
  end
end
