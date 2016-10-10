require 'asciidoctor'
require 'asciidoctor-revealjs'
require 'rake/clean'
CLEAN.include '*.html'

desc "Generate html pages using reveal.js"
task :generateReveal, [:filename, :output_dir] do |t, args|
    filename = args[:filename]
    output_dir = args[:output_dir]
    print "Generating Reveal for: \n  " + filename  + "  |||  "
    #TODO(shearer) use asciidoctor-revealjs directly, not through shell
    sh 'bundle exec asciidoctor-revealjs -a revealjsdir=https://cdnjs.cloudflare.com/ajax/libs/reveal.js/3.3.0 ' + filename
end

desc "Generate html pages using just asciidoctor"
task :generateHTML, [:filename, :output_dir] do |t, args|
    filename = args[:filename]
    output_dir = args[:output_dir]
    print "Generating HTML for: \n  " + filename + "  |||  "
    #TODO(shearer) use asciidoctor directly, not through shell
    sh 'bundle exec asciidoctor ' + filename
end

desc "Generate pdfs using asciidoctor-pdf"
task :generatePDF, [:filename, :output_dir] do |t, args|
    filename = args[:filename]
    output_dir = args[:output_dir]
    print "Generating PDF for: \n  " + filename + "  |||  "
    #TODO(shearer) use asciidoctor directly, not through shell
    sh 'bundle exec asciidoctor-pdf ' + filename
end

task :default do
    task(:generateHTML  ).execute( :filename => 'workshop01_settingUpABuildSystem.adoc')
    task(:generateReveal).execute( :filename => 'index.adoc' )
    task(:generateReveal).execute( :filename => 'lecture01_introduction.adoc')
    task(:generateReveal).execute( :filename => 'lecture02.adoc')
    task(:generateReveal).execute( :filename => 'lecture03.adoc')

    task(:generatePDF   ).execute( :filename => 'workshop01_settingUpABuildSystem.adoc')
    task(:generatePDF   ).execute( :filename => 'index.adoc' )
    task(:generatePDF   ).execute( :filename => 'lecture01_introduction.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture02.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture03.adoc')
end
