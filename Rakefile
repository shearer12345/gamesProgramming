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
    #Web pages
    task(:generateHTML  ).execute( :filename => 'workshop01_settingUpABuildSystem.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop02_myFirstSprite.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop03_movementAndTiming.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop04_oneSpriteTwoSpriteRedSpriteBlueSprite.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop05_useTheForceLuke.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop06_runSpriteRun.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop07_onScreenText.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop08_sceneManagement.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop09_bouncyBouncy.adoc')
    task(:generateHTML  ).execute( :filename => 'workshop10_dingDing.adoc')

    task(:generateReveal).execute( :filename => 'index.adoc' )
    task(:generateReveal).execute( :filename => 'lecture01_introduction.adoc')
    task(:generateReveal).execute( :filename => 'lecture02.adoc')
    task(:generateReveal).execute( :filename => 'lecture03.adoc')
    task(:generateReveal).execute( :filename => 'lecture04.adoc')
    task(:generateReveal).execute( :filename => 'lecture05.adoc')
    task(:generateReveal).execute( :filename => 'lecture06.adoc')
    task(:generateReveal).execute( :filename => 'lecture07.adoc')
    task(:generateReveal).execute( :filename => 'lecture08.adoc')
    task(:generateReveal).execute( :filename => 'lecture09.adoc')
    task(:generateReveal).execute( :filename => 'lecture10.adoc')
    task(:generateReveal).execute( :filename => 'lecture11.adoc')
    task(:generateReveal).execute( :filename => 'lecture12.adoc')
    task(:generateReveal).execute( :filename => 'lecture13.adoc')

    #PDFs
    task(:generatePDF   ).execute( :filename => 'workshop01_settingUpABuildSystem.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop02_myFirstSprite.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop03_movementAndTiming.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop04_oneSpriteTwoSpriteRedSpriteBlueSprite.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop05_useTheForceLuke.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop06_runSpriteRun.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop07_onScreenText.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop08_sceneManagement.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop09_bouncyBouncy.adoc')
    task(:generatePDF   ).execute( :filename => 'workshop10_dingDing.adoc')


    task(:generatePDF   ).execute( :filename => 'lecture01_introduction.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture02.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture03.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture04.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture05.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture06.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture07.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture08.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture09.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture10.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture11.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture12.adoc')
    task(:generatePDF   ).execute( :filename => 'lecture13.adoc')
end
